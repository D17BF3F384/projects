<?php

require_once "reset_database.php";

define('BASE_URL', str_replace('\\', '/', substr(__DIR__, strlen($_SERVER['DOCUMENT_ROOT']))));
require_once(implode(DIRECTORY_SEPARATOR, ['Core', 'autoload.php']));

$core = new Core\Core();
$core->run();

