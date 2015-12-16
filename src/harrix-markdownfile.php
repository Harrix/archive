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

add_action( 'wp_enqueue_scripts', 'harrix_add_scripts_styles' );
add_action('wp_head','harrix_load_highlight_js');
add_shortcode('markdown','harrix_markdown_make');

function harrix_add_scripts_styles()
{
    wp_register_script( 'highlight.js', plugin_dir_url( __FILE__ ) . 'highlight.min.js' );
    wp_enqueue_style( 'github.css', plugin_dir_url( __FILE__ ) . 'styles/github.css' );
    wp_enqueue_script( 'highlight.js' );
}

function harrix_load_highlight_js() {
    echo "\n<script>hljs.initHighlightingOnLoad();</script>\n";
}

function harrix_markdown_make( $atts, $content ) 
{
    $yourfile = esc_url( $content );
    $contents = file_get_contents( $yourfile );

    if ($contents === false)
          {
              $contents = "Do not downloaded $yourfile";
          }
          else
          {
              $contents = Markdown::defaultTransform($contents);

              $tr=array("<p><code>cpp\r\n"=>"<pre><code style=\"cpp\">",
                        "<p><code>cpp\n"=>"<pre><code style=\"cpp\">",
                        "<p><code>html\r\n"=>"<pre><code style=\"html\">",
                        "<p><code>html\n"=>"<pre><code style=\"html\">",
                        "<p><code>css\n"=>"<pre><code style=\"css\">",
                        "<p><code>css\r\n"=>"<pre><code style=\"css\">",
                       );
              $contents=strtr($contents,$tr);

              $tr=array('<p><code>'=>'<pre><code>',
                        '</code></p>'=>'</code></pre>');
              $contents=strtr($contents,$tr);
          }

    return $contents;
}