//Находим все вставки LaTeX в виде div класса tex и рендерим их
window.onload = function() {
  var tex = document.getElementsByClassName("tex");
  Array.prototype.forEach.call(tex, function(el) {
    katex.render(el.getAttribute("data-expr"), el,{ displayMode: true });
  });
};

//Запускаем подсветку синтаксиса
hljs.initHighlightingOnLoad();

//Работаем с заголовком при скролле страницы
$(document).ready(function(){
  $(window).scroll(function(){
    var bo = $(this).scrollTop();
    //$("#hid").html(bo);
    if ( bo >= 50) {
      $("#logo").addClass("logo-small");
      $("#header").addClass("header-small");
      $("#header-full-width").addClass("header-full-width-small");
      $("#bd-main-nav").addClass("bd-main-nav-small");
      $("#navbar-toggler").addClass("navbar-toggler-small");
    }
    else {
      $("#logo").removeClass("logo-small");
      $("#header").removeClass("header-small");
      $("#header-full-width").removeClass("header-full-width-small");
      $("#bd-main-nav").removeClass("bd-main-nav-small");
      $("#navbar-toggler").removeClass("navbar-toggler-small");
    }
  })
})