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

add_shortcode('markdown','harrix_markdown_make');
add_action('wp_head','harrix_add_highlight_js');

function harrix_add_highlight_js() {
    echo "\n\n<link rel=\"stylesheet\" href=\"//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.0.0/styles/default.min.css\">\n";
    echo "<script src=\"//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.0.0/highlight.min.js\"></script>\n";
    echo "<script>hljs.initHighlightingOnLoad();</script>\n\n";
}

function harrix_markdown_make( $atts, $content ) {

    $yourfile = esc_url( $content );
    $contents = file_get_contents( $yourfile );
    //$contents = do_shortcode( $contents );
	
    if ($contents === false)
          {
              $contents = "Do not downloaded $yourfile";
          }
          else
          {
              $contents = Markdown::defaultTransform($contents);
		  
			  //$tr=array('<p><code>'=>'<pre><code style="cpp">','</code></p>'=>'</code></pre>');
              $contents=strtr($contents,$tr);
          }

    return $contents;
}
