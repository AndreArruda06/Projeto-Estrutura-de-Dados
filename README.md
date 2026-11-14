# Projeto-Estrutura-de-Dados

## Sistema de Gerenciamento de Biblioteca

Projeto individual desenvolvido para a disciplina de Estrutura de Dados.

## Objetivo

Desenvolver um sistema de gerenciamento de biblioteca utilizando a linguagem C e aplicando os conceitos de estruturas de dados estudados na disciplina.

## Estruturas utilizadas

- Árvore Binária de Busca (BST)
- Lista encadeada
- Tipos Abstratos de Dados (TADs)

## Funcionalidades

- Cadastrar livros.
- Buscar livros pelo ID.
- Remover livros.
- Listar livros em ordem crescente de ID.
- Inserir IDs na lista encadeada.
- Remover IDs da lista encadeada.
- Exibir os IDs armazenados na lista.

## Compilação

O projeto foi desenvolvido em linguagem C, utilizando o compilador GCC no Windows.

Para compilar, execute no terminal, dentro da pasta principal do projeto:

```bash
gcc -std=c11 -Iinclude src/main.c src/bst.c src/estrutura.c -o biblioteca.exe
```

## Execução

Após a compilação, execute:

```bash
./biblioteca.exe
```

No PowerShell do Windows, também é possível utilizar:

```powershell
.\biblioteca.exe
```

## Testes

Para executar os testes automatizados, utilize o PowerShell na pasta principal do projeto:

```powershell
powershell -ExecutionPolicy Bypass -File .\tests\testeall.ps1
```

O script compila o projeto e verifica as principais funcionalidades, incluindo validações, operações da BST e da lista encadeada.

## Status do projeto

Em desenvolvimento.