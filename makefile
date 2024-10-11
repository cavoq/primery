PROJECT=primery
VERSION=1.2


help: ## Get help for Makefile
	@echo "\n#### $(PROJECT) v$(VERSION) ####\n"
	@echo "Available targets:\n"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
	@echo "\n"


build: ## Build software
	g++ -o $(PROJECT) -O3 $(wildcard main.cpp src/*.cpp)

install: build ## Install software globally
	chmod +x install.sh
	./install.sh

uninstall: ## Uninstall software
	chmod +x uninstall.sh
	./uninstall.sh

clean: ## Remove program and output files
	@rm -f $(PROJECT) *.txt