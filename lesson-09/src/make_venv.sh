#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

readonly PROJECT_DIR=$( pwd )
readonly VENV_DIR=${PROJECT_DIR}/venv

function main()
{
  rm -rf ${VENV_DIR}

  if ! python3 -m venv ${VENV_DIR} ; then
    echo "Failed to create virtual environment."
    return 1
  fi

  if ! ${VENV_DIR}/bin/pip install --upgrade pip ; then
    echo "Failed to upgrade pip."
    return 1
  fi

  if ! ${VENV_DIR}/bin/pip install -r ${PROJECT_DIR}/requirements.txt ; then
    echo "Failed to install requirements.txt."
    return 1
  fi

  # Дальше активируйте своё виртуальное окружение.
  # source venv/bin/activate
}

main ${@}
