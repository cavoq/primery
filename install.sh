#!/bin/bash

echo "Installing..."

# Step 1: Create installation directory
sudo mkdir -p /usr/local/bin/primery/bin

# Step 2: Copy program files to installation directory
sudo cp primery /usr/local/bin/primery/bin

# Step 3: Create shell script to call program
sudo tee /usr/local/bin/primery/primery >/dev/null <<EOF
#!/bin/bash
/usr/local/bin/primery/bin/primery "\$@"
EOF

# Step 4: Make shell script executable
sudo chmod +x /usr/local/bin/primery/primery

# Step 5: Add installation directory to PATH
if ! grep -q "/usr/local/bin/primery" ~/.bashrc; then
  echo 'export PATH="/usr/local/bin/primery:$PATH"' >> ~/.bashrc
fi

# Step 6: Source ~/.bashrc to update PATH
source ~/.bashrc

echo "Installation complete"