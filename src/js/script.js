window.onload = function() {
  //Находим все вставки LaTeX в виде div класса tex и рендерим их
  var tex = document.getElementsByClassName("tex");
  Array.prototype.forEach.call(tex, function(el) {
    katex.render(el.getAttribute("data-expr"), el,{ displayMode: true });
  });
  
  changeSizeFiguraInPhotoswipeGallery();
  
  //Запускаем поиск галерей, чтобы привести сетку изображений к нужному виду
  $('.photoswipe_gallery').masonry({
  // options
  itemSelector: '.msnry_item',
  fitWidth: true,  
  });
  
  $(window).resize(changeSizeFiguraInPhotoswipeGallery); 
  
};

//Запускаем подсветку синтаксиса
hljs.initHighlightingOnLoad();

function changeSizeFiguraInPhotoswipeGallery()
{
    var width_content = $(".content").width();
    var w_figura = (width_content - 40)/3;
    $(".msnry_item").width(w_figura);
}

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

