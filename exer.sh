
echo 'export PATH=/workspace/exercism/bin:$PATH' >> ~/.bash_profile
source ~/.bash_profile

[[ ":$PATH:" == *":$HOME/bin:"* || ":$PATH:" == *":/workspace/exercism/bin:"* ]] && echo "/workspace/exercism/bin is in PATH" || echo "/workspace/exercism/bin is not in PATH"

exercism configure --token=19d99b4f-858e-4a0b-82b6-f5d6d930a1e0 --workspace /workspace/exercism/
