#!/usr/bin/env bash
# Fails when README.md's firmware file names (Download link, Install step 1) differ from each other
# or from the file attached to the latest GitHub release. Needs gh (logged in, or GH_TOKEN set).
set -euo pipefail
cd "$(dirname "$0")/../.."
repo="${GITHUB_REPOSITORY:-sawtoothwave/lxr-eurorack-app}"

link=$(grep -oE 'releases/download/[^/)]+/LXRE_V2_V[^/)]+\.img' README.md | head -1 || true)
link_tag=$(echo "$link" | cut -d/ -f3)
link_file=$(echo "$link" | cut -d/ -f4)
install_file=$(grep -E '^1\. ' README.md | grep -oE 'LXRE_V2_V[^`]+\.img' | head -1 || true)
latest_tag=$(gh api "repos/$repo/releases/latest" -q .tag_name)
latest_file=$(gh api "repos/$repo/releases/latest" -q '.assets[].name' | grep -E '^LXRE_V2_V.*\.img$' | head -1)

echo "latest release:  $latest_tag  $latest_file"
echo "Download link:   $link_tag  $link_file"
echo "Install step 1:  $install_file"

fail=0
[ "$link_tag" = "$latest_tag" ]     || { echo "::error file=README.md::Download link points at $link_tag, latest release is $latest_tag"; fail=1; }
[ "$link_file" = "$latest_file" ]   || { echo "::error file=README.md::Download link file is $link_file, latest release file is $latest_file"; fail=1; }
[ "$install_file" = "$latest_file" ] || { echo "::error file=README.md::Install step 1 names '${install_file:-nothing}', latest release file is $latest_file"; fail=1; }
[ $fail = 0 ] && echo "OK: README matches the latest release"
exit $fail
