PREREQUISITE

- open ubuntu terminal

sudo service mysql start
sudo mysql
use mysql;
create user 'user'@'localhost' identified by '';
grant all privileges on *.* to 'user'@'localhost';

To run this project with apache2, you need to edit the /etc/apache2/sites-available/000-default.conf file in your ubuntu and add below the "</VirtualHost>" closing tag:

<Directory /var/www>
        AllowOverride All
</Directory>

Enable the mod_rewrite:
sudo a2enmod rewrite

Restart Apache2:
sudo service apache2 restart



SET UP THE PROJECT

Download the foler "code" from my GitHub depository. Cut all the content of "code" folder and paste it in your "www" local server folder.

