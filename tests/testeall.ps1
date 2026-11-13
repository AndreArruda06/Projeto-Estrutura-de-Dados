'teste '



$ErrorActionPreference = "Stop"

$gcc = "C:\TDM-GCC-64\bin\gcc.exe"

$aprovados = 0
$falhas = 0

function Testar($nome, $entrada, $verificacoes) {
    $processo = New-Object System.Diagnostics.Process
    $processo.StartInfo.FileName = (Resolve-Path ".\biblioteca.exe").Path
    $processo.StartInfo.UseShellExecute = $false
    $processo.StartInfo.RedirectStandardInput = $true
    $processo.StartInfo.RedirectStandardOutput = $true
    $processo.StartInfo.RedirectStandardError = $true

    $processo.Start() | Out-Null
    $processo.StandardInput.Write($entrada)
    $processo.StandardInput.Close()

    $saida = $processo.StandardOutput.ReadToEnd()
    $processo.WaitForExit()

    $resultado = $true

    foreach ($verificacao in $verificacoes) {
        if ($saida -notmatch $verificacao) {
            $resultado = $false
        }
    }

    if ($resultado) {
        Write-Host "[OK] $nome" -ForegroundColor Green
        $script:aprovados++
    } else {
        Write-Host "[ERRO] $nome" -ForegroundColor Red
        $script:falhas++
        Write-Host $saida
    }
}

Write-Host "`n===== TESTES DO PROJETO BIBLIOTECA =====`n"

# COMPILACAO
Write-Host "Compilando projeto..."

& $gcc -std=c11 -Iinclude src/main.c src/bst.c src/estrutura.c -o biblioteca.exe

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERRO] Falha na compilacao."
    exit 1
}

Write-Host "[OK] Compilacao concluida.`n" -ForegroundColor Green

# TESTE 1: ID INVALIDO E VALIDO
Testar "Validacao de ID" @'
1
0
-5
abc
10
Livro
Autor
2000
0
'@ @(
    "Valor invalido",
    "Livro cadastrado com sucesso"
)

# TESTE 2: ANO INVALIDO
Testar "Validacao do ano" @'
1
20
Livro
Autor
0
2027
2000
0
'@ @(
    "Valor invalido",
    "Livro cadastrado com sucesso"
)

# TESTE 3: ID DUPLICADO NA BST
Testar "Bloqueio de ID duplicado na BST" @'
1
10
Livro
Autor
2000
1
10
0
'@ @(
    "Esse ID ja esta cadastrado"
)

# TESTE 4: BUSCA EXISTENTE E INEXISTENTE
Testar "Busca de livros" @'
1
10
Livro
Autor
2000
2
10
2
99
0
'@ @(
    "Livro encontrado",
    "Livro nao encontrado"
)

# TESTE 5: LISTAGEM EM ORDEM
Testar "Listagem em ordem crescente" @'
1
30
Livro30
Autor
2000
1
10
Livro10
Autor
2000
1
20
Livro20
Autor
2000
4
0
'@ @(
    "ID: 10",
    "ID: 20",
    "ID: 30"
)

# TESTE 6: LISTA COM IDS REPETIDOS
Testar "Insercao de IDs repetidos na lista" @'
5
10
5
25
5
10
7
0
'@ @(
    "ID inserido na Lista",
    "10 25 10"
)

# TESTE 7: REMOCAO DO INICIO
Testar "Remocao do primeiro ID da lista" @'
5
10
5
25
6
7
0
'@ @(
    "ID removido: 10",
    "25"
)

# TESTE 8: LISTA VAZIA
Testar "Verificacao de lista vazia" @'
6
7
0
'@ @(
    "A lista esta vazia"
)

# TESTE 9: INDEPENDENCIA ENTRE BST E LISTA
Testar "Independencia da lista em relacao a BST" @'
1
10
Livro
Autor
2000
5
10
3
10
7
0
'@ @(
    "Livro removido com sucesso",
    "10"
)

# TESTE 10: REMOCAO DE LIVRO INEXISTENTE
Testar "Remocao de livro inexistente" @'
3
99
0
'@ @(
    "Livro nao encontrado"
)

# TESTE 11: TESTES ESPECIFICOS DA BST
Write-Host "`nExecutando testes de remocao da BST..."

& $gcc -std=c11 -Iinclude tests/testes_bst.c src/bst.c -o testes_bst.exe

if ($LASTEXITCODE -eq 0) {
    $resultadoBST = & .\testes_bst.exe
    $textoBST = $resultadoBST -join "`n"

    if ($textoBST -match "\[OK\] Remocao de folha" -and
        $textoBST -match "\[OK\] Remocao de no com um filho" -and
        $textoBST -match "\[OK\] Remocao de no com dois filhos") {

        Write-Host "[OK] Remocao dos tres tipos de nos da BST" -ForegroundColor Green
        $aprovados++
    } else {
        Write-Host "[ERRO] Testes de remocao da BST" -ForegroundColor Red
        $falhas++
        Write-Host $textoBST
    }
} else {
    Write-Host "[ERRO] Compilacao dos testes da BST" -ForegroundColor Red
    $falhas++
}

# RESULTADO FINAL
Write-Host "`n========== RESULTADO FINAL =========="
Write-Host "Testes aprovados: $aprovados" -ForegroundColor Green
Write-Host "Testes com falha: $falhas" -ForegroundColor Red

if ($falhas -eq 0) {
    Write-Host "`nTODOS OS TESTES PASSARAM!" -ForegroundColor Green
} else {
    Write-Host "`nEXISTEM TESTES QUE PRECISAM SER CORRIGIDOS." -ForegroundColor Red
}
