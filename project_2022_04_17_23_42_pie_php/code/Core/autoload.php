<?php

spl_autoload_register(function($class) {

    $class = str_replace("\\", "/", $class);
    $file = $class.".php";
    if(file_exists($file)) {
        require_once $file;
    }
    else if(!file_exists($file)) {
        require_once "src/".$file;
    }

});

