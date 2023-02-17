#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

function main()
{
  if ! python setup.py build_ext --inplace ; then
    echo "Failed to run setup.py build_ext --inplace."
    return 1
  fi
}

main ${@}
