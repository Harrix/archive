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
      showZeroCountItems : true,
	  };
    
    plugin.settings = $.extend({}, defaults, options);
    
    $(ul).click(toggleUl);
    
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
    
    $(input)
    .change(function() {
      var text = $(input).val().toLowerCase();
      if (text.trim())
      {
        doFilter($(ul), text);
        $(ul).find("ul").show();
        if ($(ul).find("li:visible").length == 0)
          $(ul).find(".no-results").show();
        else
          $(ul).find(".no-results").hide();
      }
      else
      {
        listTraversal ($(ul).children(), returnStateCollapse);
        $(ul).find(".no-results").hide();
      }
    })
    .on('keyup paste', function () {
      setTimeout(function () {
        $(input).change();
      }, 100);
    });
    
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
      var target = $(event.target);
      if (target.is("li")) {
        $.each( target.children(), function( i, element ) {
          var element = $(element);
          if (element.is('ul'))
          {
            element.toggle();
            toogleAttr (element, 'data-collapse', 'true', 'false');
            if (plugin.settings.listStyle == 'arrows')
              if ((target.hasClass( "collapsed" ))||(target.hasClass( "expanded" )))
                target.toggleClass('collapsed expanded');
          }
        });
      }
      else {
        if (!target.is("ul")) {
          var li = target.closest("li");
          var ulFirst = li.find('ul:first');
          ulFirst.toggle();
          toogleAttr (ulFirst, 'data-collapse', 'true', 'false');
          if (plugin.settings.listStyle == 'arrows')
            if ((li.hasClass( "collapsed" ))||(li.hasClass( "expanded" )))
              li.toggleClass('collapsed expanded');
        }
      }
    };
    
    function toogleAttr (element, name, first, second) {
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
      
      if (plugin.settings.listStyle == 'arrows')
      {
        if (element.is("ul"))
        {
          if (element.attr('data-collapse') == 'true')
            liWorkWithElement.addClass( "collapsed" );
          else
            liWorkWithElement.addClass( "expanded" );
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
            show = plugin.settings.functionSearch( getTextFromLiInNestedList(li).toLowerCase(),
                                                   filter );
          if (show)
            li.show();
          else
            li.hide();
          if (show)
            showObj = true;
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
        text = element.text();
      if (plugin.settings.searchBy == 'value') {
        text = element.data('value');
        if (text === undefined) {
          text = element.text();
        }
        else if (!text.trim()) {
          text = element.text();
        }
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
      if (textFind === undefined)
         return true;
       else if (!textFind.trim())
         return true;
      var find = false;
      if (text.indexOf(textFind) >= 0)
        find = true;
      return find;      
    };
  
    return this;
  };

})( jQuery );