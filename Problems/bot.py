#!/usr/bin/env python3
import requests
import sys

# --- CONFIGURACIÓN ---
# API de Kenkoooo (El estándar de facto para datos de AtCoder)
URL_PROBLEMS = "https://kenkoooo.com/atcoder/resources/problems.json"
URL_DIFFICULTY = "https://kenkoooo.com/atcoder/resources/problem-models.json"
URL_USER = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={}&from_second=0"

class Colors:
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BLUE = '\033[94m'
    BOLD = '\033[1m'
    END = '\033[0m'

def get_data(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        return r.json()
    except Exception as e:
        print(f"{Colors.RED}Error conectando a la API: {e}{Colors.END}")
        sys.exit(1)

def main():
    print(f"{Colors.BOLD}=== AtCoder Recommendation (API Mode) ==={Colors.END}")
    
    # 1. Obtener usuario
    if len(sys.argv) > 1:
        user_id = sys.argv[1]
    else:
        user_id = input("Usuario de AtCoder: ").strip()

    print(f"Descargando datos para: {Colors.BLUE}{user_id}{Colors.END}...")

    # 2. Descargar datos en paralelo (conceptualmente)
    problems_list = get_data(URL_PROBLEMS)
    difficulty_dict = get_data(URL_DIFFICULTY)
    user_submissions = get_data(URL_USER.format(user_id))

    # 3. Procesar lo que ya resolviste (AC)
    solved_ids = set()
    for sub in user_submissions:
        if sub['result'] == 'AC':
            solved_ids.add(sub['problem_id'])

    # 4. Cruzar problemas con dificultades
    # Estructura: (dificultad, titulo, id, contest_id)
    recommendations = []

    print("Analizando problemas...")

    for p in problems_list:
        pid = p['id']
        
        # Si ya lo resolviste, saltar
        if pid in solved_ids:
            continue

        # Si no tiene dificultad asignada (problemas muy viejos o muy nuevos), saltar
        if pid not in difficulty_dict:
            continue
        
        difficulty = difficulty_dict[pid].get('difficulty')
        
        if difficulty is None:
            continue

        # Evitar problemas experimentales con dificultad negativa si no interesan
        if difficulty < 0: 
            continue

        recommendations.append({
            'diff': difficulty,
            'title': p['title'],
            'id': pid,
            'contest': p['contest_id'],
            'url': f"https://atcoder.jp/contests/{p['contest_id']}/tasks/{pid}"
        })

    # 5. Ordenar por dificultad
    recommendations.sort(key=lambda x: x['diff'])

    # 6. Mostrar recomendaciones agrupadas (Ejemplo simple)
    # Puedes ajustar estos rangos según tu nivel
    # Easy: 400-800 (Marrón), Medium: 800-1200 (Verde), Hard: 1200-1600 (Cyan)
    
    def show_block(name, min_d, max_d, color, count=5):
        print(f"\n{color}{Colors.BOLD}--- {name} (Rating {min_d}-{max_d}) ---{Colors.END}")
        filtered = [r for r in recommendations if min_d <= r['diff'] < max_d]
        
        if not filtered:
            print("  ¡No hay problemas disponibles en este rango (o ya los hiciste todos)!")
            return

        # Mostrar los primeros 'count'
        for item in filtered[:count]:
            print(f" [{int(item['diff'])}] {item['title']}")
            print(f"      {item['url']}")

    # Muestra rangos típicos de progresión
    # Configuración para entrenamiento E/F
    # Rango 800 - 1200: Para calentar y asegurar velocidad en la D/E fácil
    show_block("WARMUP (High Green)", 800, 1200, Colors.GREEN)
    
    # Rango 1200 - 1600: Zona de Problemas E estándar
    show_block("TARGET E (Cyan/Blue)", 1200, 1600, Colors.YELLOW)
    
    # Rango 1600 - 2200: Zona de Problemas F (y G fáciles)
    show_block("TARGET F (Blue/Yellow)", 1600, 2200, Colors.RED)

    print("\nTip: Resuelve problemas +200 de tu rating actual para mejorar.")

if __name__ == "__main__":
    main()
