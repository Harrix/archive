 /*
 * File: harrixListWithFilter.js
 * Desc: list with filter.
 * Requires: jQuery.
 * License: MIT.
 */
(function( $ ){

  $.fn.harrixListWithFilter = function(ul, input) {
    $(input)
    .change(function() {
      doFilter($(ul), $(input).val().toLowerCase());
    })
    .on('keyup paste', function () {
      setTimeout(function () {
        $(input).change();
      }, 100);
    });
    
    bypassingElements ($(ul).children());
    
    //prepareList($(ul));
    
    return this;
  };
  
  function bypassingElements (children)
  {
    if (children.length > 0) {
      $.each( children, function( i, element ) {
        var element = $(element);
        
        var te = element.text();      
        console.log(te);
        
        element.click(function(event) {
          if (this == event.target) {
          var element = $(this);
        
        var te = //element.text();
    /* element
    .clone()    //clone the element
    .children() //select all the children
    .remove()   //remove all the children
    .end()  //again go back to selected element
    .text();    */
element.contents().get(0).nodeValue.toLowerCase();
        
          alert( te );
          }
        });
        
        bypassingElements(element.children());
      });
    }        
  }
  
  function prepareList(element) {
  $(element).find('li:has(ul)')
  	.click( function(event) {
  		if (this == event.target) {
  			$(this).toggleClass('expanded');
  			$(this).children('ul').toggle('medium');
  		}
  		return false;
  	})
  	.addClass('collapsed')
  	.children('ul').hide();
  };
  
  function doFilter(obj, filter) {
    var showObj = false;
    $.each( obj.children(), function( i, element ) {
      var li = $(element);
      if (li.is('li')) {
        var show = checkChildren(li.children(), filter);
        if (show == false)
          show = findString(li.contents().get(0).nodeValue.toLowerCase(), filter);
        if (show == true)
          li.show();
        else
          li.hide();
        if (show == true)
          showObj = true;
      }
    });    
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
  
  function findString(text, textFind) {
    var find = false;
    if (text.indexOf(textFind) >= 0)
      find = true;
    return find;      
  };

})( jQuery );