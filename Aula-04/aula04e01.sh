#!/bin/bash
function imprime_msg() {
	echo "A minha primeira funcao"
	return 0
}

function imprime_data() {
	date
	return 0
}

function imprime_host() {
	hostname
	return 0
}

function imprime_utilizador() {
	whoami
	return 0
}

imprime_msg
imprime_data
imprime_host
imprime_utilizador
