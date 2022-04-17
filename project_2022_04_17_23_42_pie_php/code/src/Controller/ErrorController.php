<?php

namespace Controller;

class ErrorController extends \Core\Controller {

    public function displayAction() {
        $this->render("Error/404");
    }
    
}

