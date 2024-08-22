#!/bin/bash

# Diretórios com os arquivos de mapa
VALID_DIR="maps/valid"
INVALID_DIR="maps/invalid"

# Arquivo de log para registrar as falhas
LOG_FILE="valgrind_failures.log"

# Limpa o arquivo de log anterior, se existir
> "$LOG_FILE"

# Inicializa contadores
correct_count=0
wrong_count=0

# Função para executar valgrind e verificar falhas
run_valgrind() {
    local map_file=$1
    local log_file=$2
    
    echo "Executando valgrind no arquivo: $map_file"
    valgrind --leak-check=full --show-leak-kinds=all ./cub3D_bonus "$map_file" &> "$log_file"
    
    if grep -q -E "Invalid read" "$log_file"; then
        echo "Falha encontrada no arquivo: $map_file"
        echo "==== Falha no arquivo: $map_file ====" >> "$LOG_FILE"
        cat "$log_file" >> "$LOG_FILE"
        echo -e "\n\n" >> "$LOG_FILE"
        wrong_count=$((wrong_count + 1))
    else
        rm "$log_file"
        correct_count=$((correct_count + 1))
    fi
}

# Executa valgrind em todos os arquivos inválidos
for map_file in "$INVALID_DIR"/*.cub; do
    run_valgrind "$map_file" "valgrind_log_invalid.txt"
done
# Executa valgrind em todos os arquivos válidos
for map_file in "$VALID_DIR"/*.cub; do
    run_valgrind "$map_file" "valgrind_log_valid.txt"
done

# Calcula o total de arquivos testados
total_count=$((correct_count + wrong_count))

# Exibe os resultados finais
echo ""
echo -e "Execução completa."
echo ""
echo -e "Total de mapas testados: $total_count"
echo -e "Resultado: $correct_count/$total_count"
echo -e "Total de leaks: $wrong_count"