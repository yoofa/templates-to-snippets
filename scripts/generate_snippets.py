#! /usr/bin/env python3
# vim:fenc=utf-8
#
# Copyright © 2024 youfa <vsyfar@gmail.com>
#
# Distributed under terms of the GPLv2 license.

"""

"""

import os
import json

TEMPLATES_ROOT = "templates"
SNIPPETS_ROOT = "snippets"

# Define comment prefixes for each language
COMMENT_PREFIXES = {
    "cpp": "//",
    "python": "#",
    # Add more languages as needed
}


def extract_snippets(file_path, language):
    """
    Extracts snippets information from a code file based on specific comments.
    Returns a list of dictionaries, each containing 'description', 'prefix', 'body', and 'generate_snippets' extracted.
    """
    comment_prefix = COMMENT_PREFIXES.get(
        language, "//"
    )  # Default to "//" if language not found
    snippets = []
    snippet_info = None
    in_snippet_block = False

    with open(file_path, "r", encoding="utf-8") as file:
        lines = file.readlines()

        for line in lines:
            line = line.rstrip()

            if line.lstrip().startswith(f"{comment_prefix} @snippets-start"):
                snippet_info = {
                    "description": "",
                    "prefix": "",
                    "body": [],
                    "generate_snippets": False,
                }
                in_snippet_block = True
            elif line.lstrip().startswith(f"{comment_prefix} @snippets-end"):
                if snippet_info:
                    snippets.append(snippet_info)
                    snippet_info = None
                in_snippet_block = False
            elif in_snippet_block:
                if line.lstrip().startswith(
                    f"{comment_prefix} @snippets-generate true"
                ):
                    if snippet_info:
                        snippet_info["generate_snippets"] = True
                elif line.lstrip().startswith(
                    f"{comment_prefix} @snippets-description"
                ):
                    if snippet_info:
                        snippet_info["description"] += (
                            line.split(f"{comment_prefix} @snippets-description", 1)[
                                1
                            ].strip()
                            + " "
                        )
                elif line.lstrip().startswith(f"{comment_prefix} @snippets-prefix"):
                    if snippet_info:
                        snippet_info["prefix"] += (
                            line.split(f"{comment_prefix} @snippets-prefix", 1)[
                                1
                            ].strip()
                            + " "
                        )
                elif not line.lstrip().startswith(comment_prefix):
                    if snippet_info:
                        snippet_info["body"].append(line)

    # Strip trailing spaces from description and prefix
    if snippets:
        for snippet in snippets:
            snippet["description"] = snippet["description"].strip()
            snippet["prefix"] = snippet["prefix"].strip()

    return snippets


def generate_snippets(language_dir, language):
    """
    Generates snippets file for a specific language based on template files.
    """
    snippets = {}

    for root, _, files in os.walk(language_dir):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            snippet_name = os.path.splitext(file_name)[0]
            snippet_infos = extract_snippets(file_path, language)
            for index, snippet_info in enumerate(snippet_infos):
                if snippet_info["generate_snippets"]:
                    snippets[f"{snippet_name}_{index}"] = {
                        "prefix": snippet_info["prefix"],
                        "description": snippet_info["description"],
                        "body": "\n".join(snippet_info["body"]),
                    }

    if not snippets:
        print(f"No snippets found for {language}.")
        return

    snippets_file = os.path.join(SNIPPETS_ROOT, f"{language}.json")
    with open(snippets_file, "w", encoding="utf-8") as f:
        json.dump(snippets, f, ensure_ascii=False, indent=4)


def main():
    if not os.path.exists(SNIPPETS_ROOT):
        os.makedirs(SNIPPETS_ROOT)

    for language_dir in os.listdir(TEMPLATES_ROOT):
        language_dir_path = os.path.join(TEMPLATES_ROOT, language_dir)
        if os.path.isdir(language_dir_path):
            language = (
                language_dir.lower()
            )  # Assuming directory name is lowercase language name
            generate_snippets(language_dir_path, language)

    print("Snippets generation completed.")


if __name__ == "__main__":
    main()
