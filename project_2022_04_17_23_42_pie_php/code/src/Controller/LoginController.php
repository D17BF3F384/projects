<?php

namespace Controller;

class LoginController extends \Core\Controller {

    public function displayAction() {
        $this->render("User/login");
    }
    
}

