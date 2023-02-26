#!/bin/bash

echo "Uninstalling..."

# Step 1: Remove installation directory
sudo rm -rf /usr/local/bin/primery

# Step 2: Remove PATH configuration
if grep -q "/usr/local/bin/primery" ~/.bashrc; then
  sed -i '/\/usr\/local\/bin\/primery/d' ~/.bashrc
fi

# Step 3: Source ~/.bashrc to update PATH
source ~/.bashrc

echo "Uninstallation complete"