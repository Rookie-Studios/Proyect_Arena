# Proyecto semilla — Arena

Estado del proyecto al final del curso completo (los 15 temas aplicados).
Pensado para usarse como punto de partida, no como solución cerrada:
cada clase lleva comentarios señalando a qué tema pertenece y por qué.

## Aviso importante

Este código se ha escrito siguiendo al detalle las convenciones de UE 5.8
(macros UCLASS/UPROPERTY/UFUNCTION, DOREPLIFETIME, especificadores de RPC,
estructura de módulos y de plugin), pero **no se ha compilado contra una
instalación real de Unreal Engine** — este entorno de trabajo no la tiene
disponible. Antes de usarlo en el aula:

1. Abrir el proyecto en una máquina con UE 5.8 instalado.
2. Generar los archivos de proyecto (clic derecho sobre `Arena.uproject`).
3. Compilar y corregir cualquier detalle de API que haya cambiado entre
   versiones del motor (los nombres de clase y de función son estables,
   pero conviene no asumir que compila a la primera sin revisión).

## Qué hay de cada bloque

| Bloque | Dónde está | Qué cubre |
|---|---|---|
| 0 (temas 1-3) | `Source/ArqCore/` | Las seis clases del framework, con el tiempo de vida de cada una comentado |
| 1 (temas 4-7) | `Source/ArqGameplay/Components/`, `/Interfaces/` | Composición, interfaces, el componente de vida con sus delegates |
| 2 (temas 8-9) | `Source/ArqGameplay/Data/` | `ArqEnemyDefinition`, con referencia dura y blanda una junto a la otra para comparar |
| 3 (temas 10-13) | Partición en tres módulos + `Plugins/EncuentroPlugin/` + `Tools/check_arquitectura.py` | La frontera de módulos, el plugin extraído, el check de CI |
| 4 (temas 14-15) | `ArqHealthComponent`, `AArqCharacter`, `AArqGameState`/`AArqPlayerState` | Replicación, RPCs, `HasAuthority()` |

## Defectos deliberados que hay que introducir a mano antes de cada bloque

Igual que en las guías: para que el alumnado "sienta" el problema antes de
la solución, hay que romper el proyecto a propósito antes de cada tema.

- **Antes del tema 4**: crear 3-4 variantes de enemigo por herencia (con
  características cruzadas) en una rama aparte — no está en este proyecto
  semilla porque es, precisamente, lo que cada equipo debe construir y
  luego deshacer.
- **Antes del tema 6**: colocar un Blueprint `BP_ArqEncounterManager` a
  mano en el nivel de pruebas, con referencias directas a los enemigos.
  (El Subsystem ya extraído a plugin en `Plugins/EncuentroPlugin/` es la
  solución — no se lo enseñéis hasta después del ejercicio.)
- **Antes del tema 7**: provocar al menos un cast directo real entre
  sistemas, para la actividad 7.1 (caza de casts).

## Lo que falta por completar

- Blueprints (`BP_ArqCharacter`, `BP_Enemy*`, Data Assets concretos,
  Widgets de UMG) — este proyecto semilla cubre la capa C++, los
  Blueprints se construyen en clase sobre esta base.
- Niveles de prueba.
- El workflow de CI (`.github/workflows/ci.yml`, en el paquete de
  plantillas del repositorio) asume un runner self-hosted con UE 5.8 —
  hay que configurarlo antes de que el tema 13 dependa de que funcione.
