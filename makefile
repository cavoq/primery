help: ## Get help for Makefile
	@echo "\n#### prime-generator v1.1 ####\n"
	@echo "Available targets:\n"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
	@echo "\n"


build: ## Build software
	@g++ -o prime-generator -O3 $(wildcard main.cpp src/*.cpp)

clean: ## Remove program and output files
	@rm -f prime-generator *.txt