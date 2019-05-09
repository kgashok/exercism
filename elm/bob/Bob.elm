module Bob exposing (hey)
import Char exposing (isAlpha)


hey : String -> String
hey remark =
    let
        remark_ =
            String.trim remark

        isQuestion =
            String.endsWith "?" remark_

        hasAlphabets =
            String.any isAlpha remark

        isShouting =
            String.toUpper remark == remark && hasAlphabets
    in
    if String.isEmpty remark_ then
        "Fine. Be that way!"

    else
        case ( isQuestion, isShouting ) of
            ( True, True ) ->
                "Calm down, I know what I'm doing!"

            ( _, True ) ->
                "Whoa, chill out!"

            ( True, _ ) ->
                "Sure."

            ( _, _ ) ->
                "Whatever."
