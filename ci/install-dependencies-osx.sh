# Install system dependencies
brew update
brew doctor
brew install node
brew install nvm
nvm ls
node -v

# Install module dependencies
yarn install
yarn add electron@${ElectronVersion}