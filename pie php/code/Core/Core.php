<?php

namespace Core;

class Core {

    public function run() {

        /* ---------------------------------------- *\
            static routing
        \* ---------------------------------------- */
        
        // require_once "src/routes.php";
        // $route = Router::get($_SERVER["REQUEST_URI"]);
        // $route["controller"] = ucfirst($route["controller"]);
        // $controller = "Controller\\".$route["controller"]."Controller";
        // $action = $route["action"]."Action";
        // $controller = new $controller();
        // $controller->$action();

        /* ---------------------------------------- *\
            dynamic routing
        \* ---------------------------------------- */
    

        $url = substr($_SERVER["REQUEST_URI"], 1);
        
        $error = new \Controller\ErrorController();
        if(isset($url[0]) && isset($url[1]) && isset($url[2]) && isset($url[3])) {
            if($url[0] === "?" && $url[1] === "c" && $url[2] === "=" && $url[3] !== "" && $url[3] !== "&") {
                $url = substr($url, 3);
                $position = strpos($url, "&");
                $array = [];
                for($i = 0; $i < $position; $i++) {
                    array_push($array, $url[$i]);
                }
                $controller = "Controller\\".ucfirst(implode("", $array))."Controller";
                $url = substr($url, ++$position);
                if(isset($url[2])) {
                    if($url[0] === "a" && $url[1] === "=" && $url[2] !== "&" && $url[2] !== "") {
                        $url = substr($url, 2);
                        $action = $url."Action";
                        if(method_exists($controller, $action)) {
                            $controller = new $controller();
                            $controller->$action();
                        }
                        else {
                            $error->displayAction();
                        }
                    }
                    else {
                        $error->displayAction();
                    }
                }
                else {
                    $error->displayAction();
                }
            }
            else {
                $error->displayAction();
            }
        }
        else {
            $error->displayAction();
        }

        // $array = explode("/", substr($_SERVER["REQUEST_URI"], 1));
        // print_r($array);
        // if(2 == count($array)) {
        //     $controller = "Controller\\".ucfirst($array[0])."Controller";
        //     $action = $array[1]."Action";
        //     if(method_exists($controller, $action)) {
        //         $controller = new $controller();
        //         $controller->$action();
        //     }
        //     else {
        //         echo "404";
        //         exit();
        //     }
        // }
        // else {
        //     echo "404";
        //     exit();
        // }

    }

}

