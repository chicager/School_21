mkdir /var/www/curreg
chown -R $USER:$USER /var/www/curreg
mv ./curreg /etc/nginx/sites-available/
ln -s /etc/nginx/sites-available/curreg /etc/nginx/sites-enabled/
rm /etc/nginx/nginx.conf
mv ./nginx.conf /etc/nginx/nginx.conf

service mysql start
mysql -e "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;"
mysql -e "GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY '12345';"
mysql -e "FLUSH PRIVILEGES;"

mkdir /var/www/curreg/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/curreg/phpmyadmin
rm phpMyAdmin-4.9.0.1-all-languages.tar.gz

cd /tmp 
curl -LO https://wordpress.org/latest.tar.gz
tar xzvf latest.tar.gz 
rm latest.tar.gz
cp -a /tmp/wordpress/. /var/www/curreg
chown -R www-data:www-data /var/www/curreg
rm -rf wordpress
cd
cd ..
mv ./wp-config.php ./var/www/curreg/

mkdir /etc/nginx/ssl
openssl req -x509 -nodes -days 3650 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/C=RU/ST=Moscow/l=Moscow/O=School_21/CN=curreg"

service nginx start
service php7.3-fpm start
bash