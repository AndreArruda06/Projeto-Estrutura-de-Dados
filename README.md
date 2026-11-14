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

## Ambiente de desenvolvimento

- Linguagem: C
- Padrão: C11
- Compilador: GCC (TDM-GCC-64)
- Sistema operacional: Windows

## Compilação

Abra o PowerShell na pasta principal do projeto e execute o comando:

```powershell
& "C:\TDM-GCC-64\bin\gcc.exe" -std=c11 -Iinclude src/main.c src/bst.c src/estrutura.c -o biblioteca.exe
```

## Execução

Após a compilação, execute:

```powershell
.\biblioteca.exe
```

## Testes

Para executar os testes automatizados, utilize o PowerShell na pasta principal do projeto:

```powershell
powershell -ExecutionPolicy Bypass -File .\tests\testeall.ps1
```

O script compila o projeto e verifica as principais funcionalidades, incluindo validações, operações da BST e da lista encadeada.

## Documentação dos testes

O roteiro de testes, contendo os testes manuais, automatizados e suas respectivas evidências, está disponível em:

`tests/ROTEIRO_TESTES (1).pdf`

## Relatório técnico

O relatório técnico com a descrição da modelagem, implementação, análise de complexidade, testes e conclusão está disponível em:

`docs/Relatório Técnico — Sistema de Gerenciamento de Biblioteca (1).pdf`
