module TwoFer exposing (twoFer)


twoFer : Maybe String -> String
twoFer name =
    let
        name_ =
            Maybe.withDefault "you" name
    in
    "One for " ++ name_ ++ ", one for me."
