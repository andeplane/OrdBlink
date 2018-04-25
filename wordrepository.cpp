#include "wordrepository.h"
#include <QDebug>
#include <random>

WordRepository::WordRepository(QObject *parent) : QObject(parent) {
  QStringList words = {
      "i",         "og",        "det",         "som",       "er",
      "til",       "en",        "av",          "på",        "for",
      "at",        "å",         "med",         "de",        "har",
      "den",       "ikke",      "et",          "om",        "fra",
      "var",       "han",       "men",         "seg",       "vil",
      "jeg",       "kan",       "ble",         "vil",       "skal",
      "sier",      "etter",     "så",          "år",        "også",
      "hun",       "dette",     "ved",         "da",        "blir",
      "nå",        "ut",        "være",        "hadde",     "over",
      "mot",       "eller",     "to",          "må",        "går",
      "få",        "andre",     "opp",         "sin",       "når",
      "du",        "bare",      "alle",        "ha",        "enn",
      "mer",       "denne",     "selv",        "noe",       "mange",
      "inn",       "bli",       "noen",        "vært",      "får",
      "før",       "der",       "man",         "kroner",    "nye",
      "dag",       "Norge",     "flere",       "fikk",      "første",
      "under",     "slik",      "siden",       "mye",       "norske",
      "kommer",    "både",      "kunne",       "meg",       "mellom",
      "hva",       "tre",       "her",         "store",     "mener",
      "ingen",     "dem",       "oss",         "hele",      "sine",
      "siste",     "gang",      "skulle",      "hans",      "ta",
      "helt",      "godt",      "sammen",      "sa",        "kom",
      "millioner", "hvor",      "nok",         "norsk",     "alt",
      "blant",     "tid",       "sitt",        "ville",     "uten",
      "blitt",     "igjen",     "tidligere",   "fått",      "rundt",
      "ny",        "samme",     "mens",        "annet",     "gjennom",
      "disse",     "litt",      "stor",        "står",      "gjør",
      "gå",        "ser",       "gjøre",       "gikk",      "folk",
      "ned",       "ham",       "se",          "hvis",      "derfor",
      "gamle",     "fire",      "fordi",       "mest",      "god",
      "tar",       "tilbake",   "gir",         "barn",      "like",
      "neste",     "gi",        "kanskje",     "langt",     "tatt",
      "del",       "bedre",     "komme",       "saken",     "ønsker",
      "tror",      "viser",     "først",       "måtte",     "aldri",
      "side",      "ligger",    "si",          "min",       "hvordan",
      "hos",       "tok",       "bør",         "beste",     "vår",
      "grunn",     "hver",      "sett",        "vel",       "gjort",
      "land",      "allerede",  "frem",        "heller",    "gode",
      "vet",       "jo",        "tiden",       "politiet",  "fem",
      "foto",      "fram",      "plass",       "mennesker", "ti",
      "likevel",   "svært",     "hatt",        "fortsatt",  "fjor",
      "bak",       "rett",      "viktig",      "forhold",   "la",
      "videre",    "større",    "leder",       "dermed",    "satt",
      "egen",      "nytt",      "annen",       "landet",    "imidlertid",
      "samtidig",  "mindre",    "Norges",      "Bergens",   "ifølge",
      "hvert",     "klart",     "kveld",       "deg",       "ett",
      "forteller", "mulig",     "lite",        "mål",       "gjelder",
      "tillegg",   "liv",       "dersom",      "verden",    "penger",
      "laget",     "nesten",    "stort",       "henne",     "løpet",
      "finne",     "synes",     "eneste",      "minst",     "senere",
      "mann",      "gjorde",    "årene",       "største",   "lørdag",
      "hennes",    "fleste",    "lenge",       "våre",      "dager",
      "søndag",    "kvinner",   "livet",       "begge",     "dessuten",
      "alltid",    "meget",     "unge",        "kr",        "nei",
      "kampen",    "gått",      "finnes",      "liten",     "måte",
      "ganger",    "møte",      "ofte",        "seks",      "mannen",
      "kommet",    "utenfor",   "gitt",        "foran",     "bra",
      "gjerne",    "deres",     "vei",         "arbeidet",  "året",
      "bruk",      "rekke",     "vårt",        "byen",      "fast",
      "fall",      "dagens",    "klar",        "betyr",     "særlig",
      "trenger",   "kort",      "regjeringen", "stadig",    "ja",
      "hjem",      "vant",      "bruke",       "bjørn",     "hjelp",
      "innen",     "slike",     "vanskelig",   "følge",     "eksempel",
      "problemer", "spesielt",  "små",         "ute",       "lenger",
      "fredag",    "dagen",     "all",         "holde",     "kjent",
      "full",      "lett",      "meter",       "gammel",    "tv",
      "lagt",      "kommune",   "skriver",     "spiller",   "legger",
      "støtte",    "politiske", "hjemme",      "sted",      "skole",
      "sterkt",    "arbeid",    "veldig",      "lag",       "stortinget",
      "sette",     "enkelte",   "stedet",      "ting",      "ansatte",
      "enda",      "personer",  "tro",         "holder",    "hvem",
      "lang",      "overfor",   "barna",       "høyre",     "eget",
      "sitter",    "spørsmål",  "dårlig",      "egne",      "uke",
      "altså",     "menn",      "skolen",      "hvorfor",   "kommunen",
      "funnet",    "årets",     "by",          "par",       "holdt",
      "skjer",     "bort",      "kamp",        "ennå",      "legge",
      "deler",     "håper",     "stå",         "slutt",     "sagt",
      "politisk",  "minutter",  "mandag",      "brann",     "tekst",
      "krav",      "ganske",    "tross",       "dere",      "best",
      "hus",       "finner",    "ord",         "nemlig",    "form",
      "burde",     "trolig",    "ulike",       "hverandre", "fotball",
      "torsdag",   "måneder",   "viste",       "kirke",     "riktig",
      "akkurat",   "veien",     "bilen",       "kontakt",   "heter",
      "inne",      "egentlig",  "sentrum",     "bruker",    "jobb",
      "føler",     "ellers",    "området",     "brukt",     "morgen",
      "nettopp",   "klare",     "forbindelse", "begynte",   "onsdag",
      "familien",  "uker",      "spille",      "selskapet", "åtte",
      "møter",     "vise",      "startet",     "fant",      "forslag",
      "verdens",   "imot",      "skjedde",     "nærmere",   "snart",
      "års",       "setter",    "ga",          "direkte",   "faktisk",
      "sterk",     "grad",      "samlet",      "bildet",    "samarbeid",
      "eldre",     "forrige",   "situasjonen", "slo",       "vanlig",
      "feil",      "timer",     "bygge",       "lange",     "forskjellige",
      "pris",      "betale",    "mor",         "navn",      "mitt",
      "sist",      "tidlig",    "glad",        "høy",       "tenke",
      "mine",      "ferdig",    "natt",        "vite",      "lille",
      "seier",     "satte",     "venner",      "alvorlig",  "skje",
      "filmen",    "regner",    "mat",         "far",       "huset",
      "høyt",      "kjøpe",     "bil",         "bok",       "lå",
      "lov",       "lage",      "din",         "sto",       "elevene"};

  int wordsPerDifficulty = words.size() / difficulties.size();
  wordsPerDifficulty = 500;  // hack

  int difficulty = 0;
  int counter = 0;
  for (const auto &word : words) {
    m_words[static_cast<Difficulty>(difficulty)].append(word);

    if (++counter >= wordsPerDifficulty) {
      counter = 0;
      difficulty++;

      // Cap difficulty to 5
      difficulty = std::min(difficulty, static_cast<int>(Difficulty::Hardest));
    }
  }
}

QStringList WordRepository::get(int n, Difficulty difficulty) {
  std::random_device
      rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(0, m_words[difficulty].size() - 1);

  QStringList words;

  while (words.size() < n) {
    int index = dis(gen);
    const auto &word = m_words[difficulty][index];
    if (!words.contains(word)) {
      words.append(word);
    }
  }

  return words;
}
