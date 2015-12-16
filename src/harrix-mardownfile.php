<?php
/**
 * Plugin Name: Harrix MardownFile
 * Plugin URI: https://github.com/Harrix/Harrix-MardownFile
 * Description: Harrix MardownFile is a plugin to display Mardown files with syntax highlighting in Wordpress.
 * Version: 1.1
 * Author: Sergienko Anton
 * Author URI: http://harrix.org
 * License: MIT
 */

require_once 'Michelf/Markdown.inc.php';

use \Michelf\Markdown;

add_shortcode('markdown','harrix_markdown_make');
add_action('wp_head','harrix_add_highlight_js');

function harrix_add_highlight_js() {
    echo "<script>hljs.initHighlightingOnLoad();</script>\n\n";
}

function wptuts_scripts_highlight()
{
    wp_register_script( 'highlight.js', plugin_dir_url( __FILE__ ) . 'highlight.min.js' );
    wp_enqueue_style( 'github.css', plugin_dir_url( __FILE__ ) . 'styles/github.css' );
    wp_enqueue_script( 'highlight.js' );
}
add_action( 'wp_enqueue_scripts', 'wptuts_scripts_highlight' );

function harrix_markdown_make( $atts, $content ) {

    $yourfile = esc_url( $content );
    $contents = file_get_contents( $yourfile );

    if ($contents === false)
          {
              $contents = "Do not downloaded $yourfile";
          }
          else
          {
              $contents = Markdown::defaultTransform($contents);

              $tr=array('<p><code>cpp'=>'<pre><code style="cpp">',
                        '<p><code>html'=>'<pre><code style="html">',
                        '<p><code>css'=>'<pre><code style="css">',
                       );
              $contents=strtr($contents,$tr);

              $tr=array('<p><code>'=>'<pre><code>',
                        '</code></p>'=>'</code></pre>');
              $contents=strtr($contents,$tr);
          }

    return $contents;
}
