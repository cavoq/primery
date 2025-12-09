PROJECT = primery
VERSION = 1.3
BUILD_DIR = build

.PHONY: help build install uninstall clean package

help: ## Show available targets
	@echo "\n#### $(PROJECT) v$(VERSION) ####\n"
	@echo "Available targets:\n"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
	@echo "\n"

configure: ## Configure CMake build
	@cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release

build: configure ## Build the project
	@cmake --build $(BUILD_DIR) --parallel

install: build ## Install to /usr/local/bin (may require sudo)
	@sudo cmake --install $(BUILD_DIR)

uninstall: ## Uninstall from system
	@sudo rm -f /usr/local/bin/$(PROJECT)
	@echo "Uninstalled $(PROJECT)"

clean: ## Remove build directory and output files
	@rm -rf $(BUILD_DIR)
	@rm -f $(PROJECT) *.txt

package: build ## Create distribution packages (tar.gz, .deb)
	@cd $(BUILD_DIR) && cpack

rebuild: clean build ## Clean and rebuild
