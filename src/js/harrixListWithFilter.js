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
      listStyle : 'default',
      searchBy : 'content',
      functionSearch : findString,
      collapsedStart : true,
      changeCursor : true,
      countItems : 'none',
      showZeroCountItems : true,
	  };
    
    plugin.settings = $.extend({}, defaults, options);
    
    $(ul).click(toggleUl);
    
    if (plugin.settings.collapsedStart)
    {
      $(ul).find("ul").hide().attr('data-collapse', 'true');
    }
    else
    {
      $(ul).find("ul").show().attr('data-collapse', 'false');
    }
    
    if (plugin.settings.listStyle == 'none')
      $(ul).find("li").css('list-style', 'none');

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
          }
        });
      }
      else {
        if (!target.is("ul")) {
          target.closest("li").find('ul:first').toggle();
          toogleAttr (target.closest("li").find('ul:first'), 'data-collapse', 'true', 'false');
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
  
    function doFilter(obj, filter) {
      var showObj = false;
      $.each( obj.children(), function( i, element ) {
        var li = $(element);
        if (li.is('li')) {
          var show = checkChildren( li.children(), filter );
          if (!show)
            show = plugin.settings.functionSearch( getTextFromLiInNestedList(li).toLowerCase(), filter );
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