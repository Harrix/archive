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
    {
      $(ul).find("ul").hide().attr('data-collapse', 'true');
    }
    else
    {
      $(ul).find("ul").show().attr('data-collapse', 'false');
    }
    
    if (plugin.settings.clearListStyle == true)
      $(ul).find("li").css('list-style', 'none');
      
    /*$(ul).find("ul").attr('data-count', '0');
    $(ul).find("ul").each(function (i, element) {
      var element=$(element);
      var count = element.find('li').length;
      
      var prevElement = element.prev();
      var prevLi;
      if (prevElement.is('li') == true)
      {
        prevLi = prevElement;
      }
      else
      {
        //prevLi = prevElement.closest("li");
        prevLi = prevElement;
      }
      
      prevLi.attr('data-count', count).css('color', 'red');
      
      //element.find('li').css('color', 'yellow');
      //var firstLi = element.find('li').eq(0);
      //prevLi.append( '<span class="count_li">'+count+'</span>' );
      //console.log(firstLi);
      //element.find('li').append( '<span class="count_li">'+count+'</span>' );
      //target.closest("li").find('ul:first'), 'data-collapse', 'true', 'false');
    });*/

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
      
      if (element.is("li") == true)
      {
        liWorkWithElement = element;
      }
      if (element.is("ul") == true)
      {
        var count = element.find('li').length;
        liWorkWithElement.append( '<span class="count_li">'+count+'</span>' );
      }
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