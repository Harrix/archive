<?php
/**
 * Plugin Name: Harrix MardownFileInWordpress
 * Plugin URI: https://github.com/Harrix/Harrix-MardownFileInWordpress
 * Description: Harrix MardownFileInWordpress is a plugin to display Mardown files with syntax highlighting in Wordpress.
 * Version: 1.0.0
 * Author: Sergienko Anton
 * Author URI: http://harrix.org
 * License: MIT
 */

require_once 'Michelf/Markdown.inc.php';

use \Michelf\Markdown;

add_shortcode('markdown','markdown_make');
add_action('wp_head','add_highlight_js');

function add_highlight_js() {
echo "\n\n<link rel=\"stylesheet\" href=\"//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.0.0/styles/default.min.css\">\n";
echo "<script src=\"//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.0.0/highlight.min.js\"></script>\n";
echo "<script>hljs.initHighlightingOnLoad();</script>\n\n";
}


function markdown_make( $atts, $content ){
	// У нас в тегах [markdown][/markdown] будет располагаться ссылка на файл markdown.
	// Например:
	// [markdown]https://raw.github.com/Harrix/HarrixQtLibrary/master/README.md[/markdown]
	
    $yourfile = esc_url( $content ); // подчистим ссылку на всякий случай
    $contents = file_get_contents( $yourfile ); // считаем файл по ссылке
    $contents = do_shortcode( $contents ); // на всякий случай по тексту найдем шорткоды
	
    if ($contents === false)
          {
              $contents = "Не загрузили файл $yourfile";
          }
          else
          {
 
              $contents = Markdown::defaultTransform($contents);//Непосредственно 
              //$tr=array('<p><code>'=>'<pre class="lang:c++ decode:true " >','</code></p>'=>'</pre>',);
			  
			  $tr=array('<p><code>'=>'<pre><code style="cpp">','</code></p>'=>'</code></pre>');
              $contents=strtr($contents,$tr);
          }

    return $contents;
}
