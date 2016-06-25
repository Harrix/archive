window.onload = function() {
  //Находим все вставки LaTeX в виде div класса tex и рендерим их
  var tex = document.getElementsByClassName("tex");
  Array.prototype.forEach.call(tex, function(el) {
    katex.render(el.getAttribute("data-expr"), el,{ displayMode: true });
  });
  
  /*Запускаем PhotoSwipe*/
  initPhotoSwipeFromDOM('.imgDisplay');
};

//Запускаем подсветку синтаксиса
hljs.initHighlightingOnLoad();

//Работаем с заголовком при скролле страницы
$(document).ready(function(){
  $(window).scroll(function(){
    var bo = $(this).scrollTop();
    if ( bo >= 50) {
      $("#logo").addClass("logo-small");
      $("#header-nav").addClass("header-nav-small");
      $("#header").addClass("header-small");
      $("#main-nav").addClass("main-nav-small");
      $("#navbar-toggler").addClass("navbar-toggler-small");
    }
    else {
      $("#logo").removeClass("logo-small");
      $("#header-nav").removeClass("header-nav-small");
      $("#header").removeClass("header-small");
      $("#main-nav").removeClass("main-nav-small");
      $("#navbar-toggler").removeClass("navbar-toggler-small");
    }
  })
})

var pswpElement = document.querySelectorAll('.pswp')[0];

// build items array
var items = [
    {
        src: 'https://placekitten.com/600/400',
        w: 600,
        h: 400
    },
    {
        src: 'https://placekitten.com/1200/900',
        w: 1200,
        h: 900
    }
];

// define options (if needed)
var options = {
    // optionName: 'option value'
    // for example:
    index: 0 // start at first slide
};

// Initializes and opens PhotoSwipe
var gallery = new PhotoSwipe( pswpElement, PhotoSwipeUI_Default, items, options);
gallery.init();