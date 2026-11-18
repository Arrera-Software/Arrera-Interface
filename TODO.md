# TODO — Arrera Interface 2027

Feuille de route globale pour transformer `Arrera-Interface` en centre de l'écosystème Arrera (Assistants + Arrera Hub + Arrera Markdown + futur Arrera Post-It), avec suppression complète des **Modes** et des **Lieux**.

---

## Phase 1 : Suppression des Modes et des Lieux (Nettoyage)

- [x] **Supprimer le module `manager/mode_lieu/`**
  - Retirer `CAMode`, `CALieu`, `CAModeLieu` (`.h` / `.cpp`).
  - Supprimer `config.h` (`ModeConfig` et `LieuConfig`).
- [x] **Nettoyer [`CAInterfaceSetting`](manager/setting/cainterfacesetting.h)**
  - Supprimer les attributs `mode1..6` et `lieu1..2`.
  - Supprimer tous les getters/setters/resets liés aux modes et aux lieux.
- [x] **Nettoyer [`ArreraSettingUI`](gui/setting/arrerasettingui.h) (`arrerasettingui.ui` / `.cpp`)**
  - Supprimer les onglets/pages de configuration Mode et Lieu (`idModePage`, `idLieuPage`, `idMainModePage`, `idAddMode`, `idGestMode`, `idMainLieu`, `idAddLieu`, `idManageLieu`).
  - Supprimer les slots `IDC_MODE*`, `IDC_BTNMODE*`, `IDC_LIEU*`, `IDC_RESETMODEINTERFACE`, `IDC_RESETLIEU`, etc.
- [x] **Nettoyer [`ArreraUI`](gui/arrera/arreraui.h) (`arreraui.ui` / `.cpp`)**
  - Supprimer les méthodes `loadMode()`, `loadLieu()`, `launchMode()`, `launchAppMode()`, `launchAssistantMode()`.
  - Supprimer les pages et conteneurs UI liés aux modes/lieux (`I2025`, `modeview`, `lieuview`) ainsi que les slots `on_IDC_MODE*_clicked()`, `on_IDC_LIEU*_clicked()`, `on_IDC_QUIT_clicked()`, `on_IDC_QUITLIEU_clicked()`, `on_IDC_APPMODE*_clicked()`.
  - Retirer le masquage des boutons d'assistants lié aux modes/lieux.
- [x] **Mettre à jour le projet et les ressources**
  - Retirer les fichiers supprimés de [`CMakeLists.txt`](CMakeLists.txt).
  - Nettoyer les images inutilisées (`mode*.png`, `lieu*.png`, etc.) dans [`resource.qrc`](resource.qrc) et `img/`.

---

## Phase 2 : Refactoring structurel & Migration CMake / ArreraQT

- [x] **Migrer vers ArreraQT ([`Arrera_qt`](https://github.com/Arrera-Librairy/Arrera_qt))**
  - Intégrer `Arrera_qt` dans [`CMakeLists.txt`](CMakeLists.txt) via `FetchContent`.
  - Remplacer uniquement les composants UI de `widget/` (`APushButton`, `Arrera_Theme`, `RoundedFrame` → `AFrame`, `ASearchBar`) par ceux d'`Arrera_qt` (conserver `librairy/` tel quel).
  - Utiliser `Arrera_qt` comme socle UI commun avec les autres apps Qt de l'écosystème (`Arrera Markdown`, futur `Arrera Post-It`).
- [x] **Finaliser la transition QMake -> CMake**
  - Bascule complète sur [`CMakeLists.txt`](CMakeLists.txt) (cible `arrera`, validée sur macOS) et suppression de `Arrera-Interface.pro` / `.qtcreator` / `build/`. *(Reste à valider la compilation CMake sur Linux et Windows en Phase 5.)*
- [x] **Désengorger [`ArreraUI`](gui/arrera/arreraui.cpp)** (réduit de > 1500 à ~406 lignes)
  - Séparation UI / logique métier effectuée via [`CArreraBus`](manager/communication/carrerabus.h), [`CAppManager`](manager/application/CAppManager.h), [`CArreraRecheche`](manager/search/carrerarecheche.h) et [`CTigerDemon`](manager/update/ctigerdemon.h).
- [x] **Remplacer les blocs répétitifs en dur par des structures dynamiques**
  - Remplacement des 20 slots `on_IDC_APP_001_clicked()` .. `on_IDC_APP_020_clicked()` (via `CAppManager::setupDesktopApps`) et des 12 slots `on_IDC_MOTEUR*_clicked()` par des boucles `connect()`.
- [ ] **Corriger les incohérences existantes**
  - Activer le thème `Arrera_qt` par défaut dans [`arreraui.cpp`](gui/arrera/arreraui.cpp) (`theme.setTheme(...)`) et nettoyer les warnings restants (`Q_OS_MAC` déprécié sous Qt 6, `nodiscard` dans `cjsonword.cpp`, `else` dans `assistant.cpp`).
  - Vérifier la compatibilité Qt 6 sur macOS, Linux et Windows.

---

## Phase 3 : Refonte de la communication (Bus Arrera & Framework ANN)

- [ ] **Spécifier le protocole du bus (avant implémentation dans les autres apps)**
  - Définir un format structuré (JSON) avec : `version`, `source`, `target`, `type` (`request`, `response`, `event`), `action`, `payload`, `request_id`.
  - Définir l'enregistrement des clients (`register`) avec leur type (`assistant` ANN, `hub`, `app`) et leurs capacités supportées.
- [ ] **Faire évoluer [`CArreraServeur`](manager/socket/carreraserveur.h) et [`CArreraBus`](manager/communication/carrerabus.h)**
  - Unifier la communication de l'écosystème (au lieu de deux serveurs texte séparés sur les ports `6666` et `2026`, ou en standardisant leur protocole).
  - Gérer proprement plusieurs clients connectés en simultané via `nameToSocket` (ne plus limiter à un seul `nameAssistantConnected`).
  - Ajouter la gestion des déconnexions par client (signal avec le nom du client déconnecté) et un heartbeat/statut de connexion fiable.
- [ ] **Refondre le routeur [`assistant`](manager/communication/assistant.h) (ANN)**
  - Remplacer le parsing texte basique (`message.contains("ouvre")`) par un vrai dispatcher JSON pour les assistants ANN.
  - Exposer dès la connexion d'un assistant : la liste des applications PC configurées, des applications spéciales (`CAppSpeciaux`), et des applications Arrera disponibles/connectées.
  - Permettre le routage inter-clients (ex. un assistant ANN envoie une commande vers `markdown`, `post-it` ou `hub` via `CArreraBus`).
  - Gérer des retours riches vers l'UI (pas uniquement une chaîne sur `LINDICATIONARRERA`, mais réponses structurées, statuts d'actions, erreurs explicites).

---

## Phase 4 : Centre de l'écosystème Arrera

- [ ] **Arrera Hub ([`CArreraApp`](manager/application/carreraapp.h))**
  - Conserver la lecture du `config.ini` d'Arrera Hub pour les apps installées, tout en ajoutant des échanges ANN temps réel (état d'installation, mises à jour disponibles, lancement/installation à la demande).
  - Assurer une gestion propre du lancement d'apps sur Windows, Linux et macOS.
- [ ] **Arrera Markdown (en coordination avec sa prochaine update)**
  - Définir les actions ANN que Markdown exposera (ex. ouvrir une note, créer/ajouter du contenu depuis un assistant, lister les notes récentes).
  - Intégrer les raccourcis et interactions correspondantes dans Arrera Interface.
- [ ] **Arrera Post-It (préparation pour futur dev)**
  - Prévoir les contrats d'API ANN et l'intégration dynamique dans l'interface (détection si installé/connecté, sans erreur si absent pour la sortie 2027).
  - Définir les cas d'usage avec les assistants (créer, consulter, épingler ou supprimer un post-it via ANN).
- [ ] **Applications PC, Spéciales & Recherche ([`CAppPC`](manager/application/capppc.h), [`CAppSpeciaux`](manager/application/cappspeciaux.h), [`CArreraRecheche`](manager/search/carrerarecheche.h))**
  - Rendre toutes ces actions pilotables proprement via ANN en plus des clics UI.

---

## Phase 5 : Nouvelle UI/UX 2027 & Stabilisation

- [ ] **Refonte de l'interface principale (`arreraui.ui`)**
  - Repenser l'accueil autour de l'écosystème : statut des assistants connectés, accès direct aux apps Arrera (Hub, Markdown, futur Post-It), recherche unifiée (Web / ANN), apps PC et retours des assistants.
  - Adapter le système de thème (`Arrera_Theme` d'`Arrera_qt`).
- [ ] **Intégrer les paramètres dans l'interface principale (fin des 2 fenêtres séparées)**
  - Intégrer la vue des paramètres directement dans [`ArreraUI`](gui/arrera/arreraui.h) (page dans le `QStackedWidget` principal ou widget/composant embarqué) au lieu d'ouvrir une fenêtre séparée [`ArreraSettingUI`](gui/setting/arrerasettingui.h).
  - Supprimer la gestion de seconde fenêtre (`uipara.show()`, signal `parametresFerme`) et appliquer/recharger les réglages directement lors du retour à l'accueil.
  - Simplifier les catégories (Général, Assistants / ANN, Écosystème Arrera, Applications PC, Recherche).
- [ ] **Mises à jour & Déploiement multi-OS**
  - Vérifier le fonctionnement de [`CTigerDemon`](manager/update/ctigerdemon.h) / [`WindowsMaj`](gui/update/windowsmaj.h) pour la version 2027.
  - Tester la compilation et l'exécution complète sur **macOS**, **Linux** et **Windows** (démarrage, connexion WebSocket multi-clients, lancement des apps).
