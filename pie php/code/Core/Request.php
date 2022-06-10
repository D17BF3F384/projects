<?php

namespace Core;

class Request {

    protected $email;
    protected $password;

    public function __construct() {
        $this->email = htmlentities(htmlspecialchars(strip_tags($_POST["email"])));
        $this->password = htmlentities(htmlspecialchars(strip_tags($_POST["password"])));
    }

    public function getEmail() {
        return $this->email;
    }

    public function getPassword() {
        return $this->password;
    }

}

