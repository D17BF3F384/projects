<?php

namespace Controller;

use Model;
use Core;

class UserController extends \Core\Controller {

    public $request;

    public function __construct() {
        $this->request = new Core\Request();
    }

    public function registerAction() {
        $array = [];
        $array["email"] = $this->request->getEmail();
        $array["password"] = $this->request->getPassword();
        $user = new Model\UserModel($array);
        $user->save();
    }

    public function loginAction() {
        $array["email"] = $this->request->getEmail();
        $array["password"] = $this->request->getPassword();
        $user = new Model\UserModel($array);
        $user->loginCheck();
    }

}

