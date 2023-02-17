#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

function main()
{
  if ! python setup.py install ; then
    echo "Failed to run setup.py install"
    return 1
  fi
}

main ${@}
