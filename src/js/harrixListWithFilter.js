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
      clearListStyle : true,
      searchBy : 'content',
      functionSearch : findString,
      collapsedStart : true,
      changeCursor : true,
	  };
    
    plugin.settings = $.extend({}, defaults, options);
    
    $(ul).click(toggleUl);
    
    if (plugin.settings.collapsedStart == true)
      $(ul).find("ul").hide();
    
    if (plugin.settings.clearListStyle == true)
      $(ul).find("li").css('list-style', 'none');

    listTraversal ($(ul).children(), workWithElement);
    
    $(input)
    .change(function() {
      doFilter($(ul), $(input).val().toLowerCase());
      $(ul).find("ul").show();
    })
    .on('keyup paste', function () {
      setTimeout(function () {
        $(input).change();
      }, 100);
    });
  
    function toggleUl(event) {
      var target = $(event.target);
      if (target.is("li")) {
        $.each( target.children(), function( i, element ) {
          var element = $(element);
          if (element.is('ul'))
            element.toggle();
        });
      }
      else {
        if (!target.is("ul")) {
          target.closest("li").find('ul:first').toggle();
        }
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
    
    function workWithElement (element) {
      if (plugin.settings.changeCursor == true)
      {
        if (isLiTreeLeaf(element) == true)
          element.css('cursor', 'pointer');
        else
        {
          if ((!element.is("li"))&&(!element.is("ul")))
          {
            if (isLiTreeLeaf(element.closest("li")) == true)
              element.css('cursor', 'pointer');
            else
              element.css('cursor', 'default');
          }
        else
          element.css('cursor', 'default');          
        }
      }
      
      /*element.click(function(event) {
        if (this == event.target) {
          var element = $(this);    
          var text = getTextFromLiInNestedList(element);  
          alert( text );
        }
      });*/      
    };
  
    function doFilter(obj, filter) {
      var showObj = false;
      $.each( obj.children(), function( i, element ) {
        var li = $(element);
        if (li.is('li')) {
          var show = checkChildren( li.children(), filter );
          if (show == false)
            show = plugin.settings.functionSearch( getTextFromLiInNestedList(li).toLowerCase(), filter );
          if (show == true)
            li.show();
          else
            li.hide();
          if (show == true)
            showObj = true;
        }
      });
      if (obj.is('li'))
        if (showObj == true)
          obj.show();
        else
          obj.hide();
      return showObj;
    };
    
    function checkChildren(children, filter) {
      var show = false;
      if (children.length > 0) {
        $.each( children, function( i, element ) {
          if (doFilter($(element), filter) == true)
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