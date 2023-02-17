#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

function main()
{
  if ! gcc -fPIC -shared -o libutils.so utils.c ; then
    echo "Failed to build shared library."
    return 1
  fi
}

main ${@}
