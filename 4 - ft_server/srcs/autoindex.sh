if grep -q "autoindex off;" /etc/nginx/sites-available/curreg
then sed -i 's/autoindex off;/autoindex on;/' /etc/nginx/sites-available/curreg
else
sed -i 's/autoindex on;/autoindex off;/' /etc/nginx/sites-available/curreg
fi
service nginx reload
