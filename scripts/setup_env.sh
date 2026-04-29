#!/bin/bash

# UAV Systems Architecture - Environment Setup Script
# This script initializes the development environment for the Sovereign Skies Framework.

echo "🛰️ Initializing UAV Systems Architecture Environment..."

# Check for dependencies
dependencies=("git" "mermaid-cli" "python3")

for dep in "${dependencies[@]}"; do
    if ! command -v $dep &> /dev/null; then
        echo "⚠️ Warning: $dep is not installed."
    else
        echo "✅ $dep found."
    fi
done

echo "🚀 Setup complete. Ready for architectural modeling."
