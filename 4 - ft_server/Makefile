.PHONY: build, run

BOLD = \033[1m
COLOR_REGULAR = \033[0m
COLOR_GREEN = \033[32m

build:
	docker build -t ft_server .
	@echo "\n$(BOLD)$(COLOR_GREEN)Successfully Built!$(COLOR_REGULAR)"

run:
	@echo "$(BOLD)$(COLOR_GREEN)Running...$(COLOR_REGULAR)"
	docker run -it -p 80:80 -p 443:443 ft_server