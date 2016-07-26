 /*
 * File: harrixListWithFilter.js
 * Desc: list with filter.
 * Requires: jQuery.
 * License: MIT.
 */
(function( $ ){

  $.fn.harrixListWithFilter = function(ul, input, options) {
    
    var plugin = this;
    
    var defaults = {
      changeCursor : true,
      collapsedStart : 'none',
      countItems : 'none',
      functionSearch : findString,
      listStyle : 'default',
      paddingLi : 'default',
      searchBy : 'content',
      showSubListByFilter : false,
      showZeroCountItems : true,
	  };
    
    plugin.settings = $.extend({}, defaults, options);
    
    $(ul).click(toggleUl);
    
    setOptionCollapsedStart();
    
    if (plugin.settings.listStyle == 'default')
    {
      $(ul).find("li").css('list-style', 'inherit');
    }
    if (plugin.settings.listStyle == 'none')
    {
      $(ul).find("li").css('list-style', 'none');
      $(ul).css('padding-left', '0px');
    }
    if (plugin.settings.listStyle == 'arrows')
    {
      $(ul).find("li").css('list-style', 'none');
      $(ul).css('padding-left', '0px');
    }

    listTraversal ($(ul).children(), workWithElement);
    listTraversal ($(ul).children(), distributeCollapsedExpanded);
    
    $(input)
    .change(function() {
      var filter = $(input).val().toLowerCase();
      $(ul).find("li").removeAttr('data-find');
      if (filter.trim())
      {
        doFilter($(ul), filter);
        $(ul).find("ul").show();
        
        $(ul).find("li:visible").each(function (index, element) {
          var element = $(element);
          if (element.find("li:visible").length > 0)
          {
            if ((element.hasClass('collapsed'))||(element.hasClass('expanded')))
            {
              element.removeClass('collapsed');
              element.addClass('expanded');
            }
          }
          else
          {
            if ((element.hasClass('collapsed'))||(element.hasClass('expanded')))
            {
              element.removeClass('expanded');
              element.addClass('collapsed');
            }
          }
        });
        
        if ($(ul).find("li:visible").length == 0)
          $(ul).find(".no-results").show();
        else
          $(ul).find(".no-results").hide();
        
        if (plugin.settings.showSubListByFilter)
        {
          $(ul).find("[data-find='true']").each(function (index, element) {
            var element = $(element);
            element.find('ul').hide().attr('data-collapse', 'true');
            element.find('li').show();
          });
        }
      }
      else
      {
        listTraversal ($(ul).children(), returnStateCollapse);
        listTraversal ($(ul).children(), distributeCollapsedExpanded);
        $(ul).find(".no-results").hide();
      }
    })
    .on('keyup paste', function () {
      setTimeout(function () {
        $(input).change();
      }, 100);
    });
    
    function setOptionCollapsedStart() {
      if (plugin.settings.collapsedStart == 'all')
      {
        $(ul).find("ul").hide().attr('data-collapse', 'true');
      }
      if (plugin.settings.collapsedStart == 'none')
      {
        $(ul).find("ul").show().attr('data-collapse', 'false');
      }
      if (plugin.settings.collapsedStart == 'close-last-ul')
      {
        $(ul).find("ul").each(function (index, element) {
          var element = $(element);
          if (element.find('ul').length == 0 )
            element.hide().attr('data-collapse', 'true');
          else
            element.show().attr('data-collapse', 'false');
        });
      }
      if (plugin.settings.collapsedStart == 'first-open')
      {
        $(ul).find("ul").hide().attr('data-collapse', 'true');
        $.each( $(ul).children(), function( i, element ) {
          var element = $(element);
          if (element.is('li'))
          {
            $.each( element.children(), function( i, element ) {
              var element = $(element);
              if (element.is('ul'))
                element.show().attr('data-collapse', 'false');
            });
          }
        });
      }     
    };
    
    function returnStateCollapse (element) {
      var element = $(element);
      if (element.is('ul'))
      {
        if (element.attr('data-collapse') == 'true') {
          element.hide();
        } else {
          element.show();
        }
      }
      else if (element.is('li')) {
        element.show();
      }
    };
  
    function toggleUl(event) {
      var filter = $(input).val().toLowerCase();
      if ((!filter.trim()) || ((plugin.settings.showSubListByFilter))) {        
        var target = $(event.target);
        if (target.is("li")) {
          $.each( target.children(), function( i, element ) {
            var element = $(element);
            if (element.is('ul'))
            {
              element.toggle();
              toggleAttr (element, 'data-collapse', 'true', 'false');
              toggleCollapsEdexpanded (target, element);
            }
          });
        }
        else {
          if (!target.is("ul")) {
            var li = target.closest("li");
            var ulFirst = li.find('ul:first');
            ulFirst.toggle();
            toggleAttr (ulFirst, 'data-collapse', 'true', 'false');
            toggleCollapsEdexpanded (li, ulFirst);
          }
        }
      }
    };
    
    function toggleCollapsEdexpanded (li, ul)
    {
      if (plugin.settings.listStyle == 'arrows')
        if ((li.hasClass( "collapsed" ))||(li.hasClass( "expanded" )))
          if (ul.attr('data-collapse') == 'true') {
              li.addClass('collapsed');
              li.removeClass('expanded');
            }
            else {
              li.addClass('expanded');
              li.removeClass('collapsed');
            }      
    };
    
    function toggleAttr (element, name, first, second) {
      if (element.attr(name) == first) {
        element.attr(name, second);
      } else {
        element.attr(name, first);
      }
    };
    
    function listTraversal (list, processingElement)
    {
      if (list.length > 0) {
        $.each( list, function( i, element ) {
          var element = $(element);        
          processingElement (element);        
          listTraversal(element.children(), processingElement);
        });
      }
    };

    var liWorkWithElement;    
    function workWithElement (element) {
      if (plugin.settings.changeCursor)
      {
        if (isLiTreeLeaf(element))
          element.css('cursor', 'pointer');
        else
        {
          if ((!element.is("li"))&&(!element.is("ul")))
          {
            if (isLiTreeLeaf(element.closest("li")))
              element.css('cursor', 'pointer');
            else
              element.css('cursor', 'default');
          }
        else
          element.css('cursor', 'default');          
        }
      }
      
      if (plugin.settings.paddingLi === 'left-leafs')
      {
        if (element.is("li"))
          if (isLiTreeLeaf(element))
            element.addClass('padding-left');
      }
      if (plugin.settings.paddingLi === 'none')
      {
        element.css('padding-left','0px');
      }
      
      if (element.is("li"))
        liWorkWithElement = element;
      
      if (plugin.settings.countItems == 'all-li')
      {
        if (element.is("ul"))
        {
          var count = element.find('li').length;
          if ((plugin.settings.showZeroCountItems) || 
             ((!plugin.settings.showZeroCountItems) && (count > 0)))
            liWorkWithElement.prepend( '<span class="count_li">'+count+'</span>' );
        }
      }
      if (plugin.settings.countItems == 'only-leafs')
      {
        if (element.is("ul"))
        {
          var count = 0;
          element.find('li').each(function (index, element) {
            var element = $(element);
            if (element.find('ul').length == 0)
              count++;
          });
          if ((plugin.settings.showZeroCountItems) || 
             ((!plugin.settings.showZeroCountItems) && (count > 0)))
            liWorkWithElement.prepend( '<span class="count_li">'+count+'</span>' );
        }
      }
    };
    
    function distributeCollapsedExpanded (element) {
      if (element.is('li'))
      {
        if (!isLiTreeLeaf(element))
        {
          var ulForLi = element.find('ul:first');
          if (ulForLi.attr('data-collapse') == 'true')
          {
            element.addClass( "collapsed" );
            element.removeClass( "expanded" );
          }
          else
          {
            element.addClass( "expanded" );
            element.removeClass( "collapsed" );
          }
        }
      }
    };
  
    function doFilter(obj, filter) {
      var showObj = false;
      $.each( obj.children(), function( i, element ) {
        var li = $(element);
        if (li.is('li')) {
          var show = checkChildren( li.children(), filter );
          if (!show)
          {
            var text = getTextFromLiInNestedList(li).toLowerCase();
            show = plugin.settings.functionSearch( text, filter );
            if (show)
              li.attr('data-find','true');
          }
          if (show)
          {
            showObj = true;
            li.show();
          }
          else
            li.hide();
        }
      });
      if (obj.is('li'))
        if (showObj)
          obj.show();
        else
          obj.hide();
      return showObj;
    };
    
    function checkChildren(children, filter) {
      var show = false;
      if (children.length > 0) {
        $.each( children, function( i, element ) {
          if (doFilter($(element), filter))
            show = true;
        });
      }
      return show;      
    };
    
    function getTextFromLiInNestedList (element)
    {
      var text;
      if (plugin.settings.searchBy == 'content')
      {
        text = getTextToNewLine (element);
      }
      if (plugin.settings.searchBy == 'value') {
        text = element.data('value');
        if (text === undefined) {
          text = getTextToNewLine (element);
        }
        else if (!text.trim()) {
          text = getTextToNewLine (element);
        }
      }
      return text;
    };
    
    function getTextToNewLine (element)
    {
      var text = element.text();
        if (text.indexOf('\n') >= 0) {
          text = text.substring(0, text.indexOf('\n'));
        }
        return text;
    };
    
    function isLiTreeLeaf(element) {
      if (element.is('li'))
        {
          if (element.children().find('li').length > 0)
            return false;
          else
            return true;
        }
      return false;
    };
    
    function findString(text, textFind) {
      var find = false;
      if (text.indexOf(textFind) >= 0)
        find = true;
      return find;      
    };
  
    return this;
  };

})( jQuery );