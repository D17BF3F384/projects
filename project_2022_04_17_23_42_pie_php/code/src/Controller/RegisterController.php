<?php

namespace Controller;

class RegisterController extends \Core\Controller {

    public function displayAction() {
        $this->render("User/register");
    }
    
}

