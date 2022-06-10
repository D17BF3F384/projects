<?php

echo
'
<form method="POST" action="http://localhost/?c=user&a=login">
    <div>email</div>
    <input type="text" name="email" required>
    <div>password</div>
    <input type="password" name="password" required>
    <div><button type="submit" name="login">log in</button></div>
</form>
';

