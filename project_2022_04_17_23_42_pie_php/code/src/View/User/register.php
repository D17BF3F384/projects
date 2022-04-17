<?php

echo
'
<form method="POST" action="http://localhost/?c=user&a=register">
    <div>email</div>
    <input type="text" name="email" required>
    <div>password</div>
    <input type="password" name="password" required>
    <div><button type="submit" name="register">register</button></div>
</form>
';

