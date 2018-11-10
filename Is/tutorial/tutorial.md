**Configuracion básica**

Nombre del administrador:

`git config --global user.name "Antonio M Durán Rosal"`

Correo electrónico:

`git config --global user.email aduran@uco.es`

Editor de texto:

`git config --global core.editor "gedit"`

Color de la interfaz:

`git config --global color.ui true`

Listado de la configuración:

`git config --list`

**Comandos básicos**

Iniciar repositorio en un directorio:

`git init`

Agregar cambios al area de staging:

`git add`

Validar cambios en el repositorio:

`git commit -m "Mensaje"`

Hacer los dos pasos anteriores en uno:

`git commit -am "Mensaje"`

Historial de commits:

`git log`

**Comandos básicos II**

Ayuda del listado anterior:

`git help log`

Listar los 5 commits más recientes:

`git log -n 5`

Listar los commits desde una fecha:

`git log --since=2018-09-18`

Listar los commits por autor:

`git log --author="Antonio"`

Ver cambios en el directorio:

`git status`

**Comandos básicos III**

Ver diferencia entre ficheros en el directorio y el repositorio del git:

`git diff`

Ver diferencia entre ficheros en el staging y el repositorio:

`git diff --staged`

Eliminar archivos:

~~~
git rm archivos
git commit -m "Mensaje"
~~~

Mover o renombrar archivos:

~~~
git mv antiguo nuevo
git commit -m "Mensaje"
~~~

**Comandos básicos IV**

Deshacer cambios con git:

`git checkout --nombre_fichero`

Retirar archivos del staging

`git reset HEAD nombre_fichero`

Complementar último commit:

`git commit --amend -m "Mensaje"`

Recuperar version de un fichero de commit antiguo:

`git checkout <id_commit> --nombre_archivo`

Revertir un commit:

`git revert <id_commit>`

**Comandos básicos V**

Deshacer multiples cambios en el repositorio:
~~~
git reset --soft <id_commit>
git reset --mixed <id_commit>
git reset --hard <id_commit>
~~~

Listar archivos que git no controla:

`git clean -n`

Eliminar archivos que git no controla:

`git clean -f`

Ignorar archivos en el repositorio: .gitignore

**Comandos básicos VI**

Listar el contenido del repositorio de git:
~~~
git ls-tree master
git ls-tree master^^^
git ls-tree master~3
~~~

Log en una línea:

`git log --oneline`

Log con los tres últimos commits en una línea:

`git log --oneline -3`

Para más opciones consultar documentación de git.

**Comandos básicos VII**

Examinar el contenido de un commit:

`git show <id>`

Comparar un commit con el actual:

`git diff <id> nombre_archivo`

Comparar dos commits:

`git diff id..id nombre_archivo`

## Ramas

**Comandos Ramas I**

Ver listado de ramas:

`git branch`

Crear una rama:

`git branch nombre_rama`

Cambiarnos a una rama:

`git checkout nombre_rama`

Crear una rama y moverse en un paso:

`git checkout -b nombre_rama`

Comparar ramas:

`git diff nombre_rama..nombre_rama`

**Comandos Ramas II**

Ver ramas idénticas a la actual:

`git branch --merged`

Renombrar ramas:

`git branch -m nombre_antiguo nombre_nuevo`

Eliminar ramas
~~~
git branch -d nombre_rama
git branch -D nombre_rama
~~~

Integrar ramas a la actual:

`git merge nombre_rama`

Resolver conflictos (se suele hacer manualmente):

`git merge --abort`

**Comandos Ramas III**

  Almacenar cambios temporales:

  `git stash save "Mensaje"`

  Listar cambios:

  `git stash list`

  Ver contenido de un cambio temporal:

  `git stash show -p nombre_stash`

  Eliminar un cambio temporal:

  `git stash drop nombre_stash`

  Aplicar cambio del *stash* :
  ~~~
  git stash apply nombre_stash
  git stash pop nombre_stash
  ~~~

# **GitHub**
**Comandos GitHub I**

  Añadir repositorio remoto:

  `git remote add origin url`

  Ver repositorios remotos:

  `git remote -v`

  Eliminar repositorio remoto:

  `git remote rm origin`

  Añadir cambios del repositorio local al remoto:

  `git push -u origin master`

  Añadir cambios del repositorio remoto al local:

  `git pull`

**Comandos GitHub II**

  Ver *branches* remotos:

  `git branch -r`

  Ver todos los *branches* :

  `git branch -a`

  Clonar un repositorio remoto:

  `git clone url`

**Dar seguimiento a** *branches* **remotos**

  LOCAL -> REMOTO

    1. Cambios en el repositorio local.
    2. Commit de los cambios.
    3. Añadir cambios a repositorio remoto:

    `git push`

  REMOTO -> LOCAL
  * Sincronización y unión:
    ~~~
    git fetch origin
    git merge origin/master
    ~~~
  * En un solo paso:

    `git pull`

**Operaciones con** *branches* **remotos**

  * Creación:
    1. Crear branch local.
    2. Hacer cambios en dicho branch.
    3. Hacer commit.
    4. Copiar el branch al repositorio remoto:

    `git push -u origin branch_remoto`

  * Copia:

  `git checkout -b local remoto`

  * Eliminacion:

  `git push origin --delete branch_remoto`
