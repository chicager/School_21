FROM debian:buster

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y \
    apt-utils wget curl \
    nginx mariadb-server \
    php-fpm php-mysql php-curl php-gd php-intl \
    php-mbstring php-soap php-xml php-xmlrpc php-zip

COPY ./srcs/nginx.conf ./
COPY ./srcs/wp-config.php ./
COPY ./srcs/curreg ./
COPY ./srcs/autoindex.sh ./
COPY ./srcs/install.sh ./

EXPOSE 80 443

CMD bash install.sh