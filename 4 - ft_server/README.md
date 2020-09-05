
### LEMP stack webserver on Debian + Wordpress + phpmyadmin + ssl cert + autoredirect to https + autoindex on/off deployed in a Docker container

------------
❗*You have to have [**Docker**](http://www.docker.com/) installed on your machine to run this project.*

------------
Please see the **en.subject.pdf** file for getting the assignments.

------------
#### Build and Run:

- Download the files
- Run Docker terminal

-- and
```
cd ft_server
make build
make run
```
-- or
```
cd ft_server
docker build -t ft_server .
docker run -it -p 80:80 -p 443:443 ft_server
```

------------
Go to `http://localhost` and you will see redirect to `https://localhost` (it will inform you that a certificate is untrasted select Proceed anyway) and the Wordpress start window. Create any random website.

To test **phpmyadmin** go to `https://localhost/phpmyadmin`<br/>Login: wordpress_user<br/>Password: 12345<br/>(You can find those info in the config file located in srcs/wp-config.php)

Autoindex is on by default, you can test it by moving to any folder without any index.&ast;  file, for example `http://localhost/phpmyadmin/themes` and you will be able to see all files inside it. To swap **autoindex on/off** type in the running container: 
```
bash autoindex.sh
```

------------
