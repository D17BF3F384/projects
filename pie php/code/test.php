<?php

namespace Core;

class Controller {

    public static $_render;
    public static $_content;

    protected function render($view, $scope = []) {

        extract($scope);
        $f = implode(
            DIRECTORY_SEPARATOR, [
                dirname(__DIR__),
                "src",
                "View",
                basename(get_class($this)),
                $view
            ]
        ).".php";

        echo get_class($this).PHP_EOL;
        $f = str_replace("\\", "/", $f);
        echo $f;

        if(file_exists($f)) {
            ob_start();
            include($f);
            self::$_content = ob_get_clean();
            ob_start();
            include(implode(DIRECTORY_SEPARATOR, [dirname(__DIR__), "src", "View", "index"]).".php");
            self::$_render = ob_get_clean();
        }
    }

    public function __destruct() {
        echo self::$_render;
    }

}


class LoginController extends \Core\Controller {

    public function addAction() {
        $this->render("login");
    }
    
}

$controller = new \Core\LoginController();
$controller->addAction();

