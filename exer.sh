
echo 'export PATH=/workspace/exercism/bin:$PATH' >> ~/.bash_profile
source ~/.bash_profile

[[ ":$PATH:" == *":$HOME/bin:"* || ":$PATH:" == *":/workspace/exercism/bin:"* ]] && echo "/workspace/exercism/bin is in PATH" || echo "/workspace/exercism/bin is not in PATH"
